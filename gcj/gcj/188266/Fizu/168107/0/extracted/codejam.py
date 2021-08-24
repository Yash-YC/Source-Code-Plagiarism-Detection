"""
Some CodeJam base classes with multi-thread support.

author: Martin Conte Mac Donell <Reflejo@gmail.com>
"""

import multiprocessing as processing
import sys
from Queue import Empty
from optparse import OptionParser

_IN_FILE = 'input.in'

try:
    import psyco
    psyco.full()
except:
    pass

def parsein(fmt, pset):
    all = pset.split(' ')
    for i, f in enumerate(fmt.lower()):
        if f == 'i':
            all[i] = int(all[i])

        elif f == 'f':
            all[i] = float(all[i])

    return all

def _parse_options():
    parser = OptionParser()
    parser.add_option("-d", "--debug", dest="debug", 
                      action="store_true", default=False, 
                      help="Show debug information")
    parser.add_option("-w", "--workers", dest="workers", default="1",
                      type="int", help="Number of workers proccess")
    parser.add_option("-i", "--inputfile", dest="infile", default=_IN_FILE,
                      type="str", help="Input file path")
    (options, args) = parser.parse_args()
    return options

def _collect(fp):
    M = parsein('i', fp.readline())
    return M, []

def _scollect(fp, first):
    return []
     
class Solver(processing.Process):

    def __init__(self, readq, solveq, debug, cache, first, collection):
        self._cache = cache
        self._solveq = solveq
        self._readq = readq
        self._debug = debug
        self.first = first
        self.collection = collection
        super(Solver, self).__init__()

    def debug(self, msg):
        """
        Print message including thread name only if debug mode is enabled
        """
        if self._debug:
            print "%s" % (msg)

    def run(self):
        """
        Start new thread, listen read queue, process message and save into 
        solve queue.
        """
        self.debug('Starting new thread')
        while True:
            try:
                i, pset = self._readq.get(block=False)
            except Empty:
                break

            result = self.solve(pset)
            self._solveq.put((i, result))
        self.debug('Finishing thread')


class Problem(object):
    
    def __init__(self, solver, cachefc=None):
        options = _parse_options()
        self._debug = options.debug
        self._workers = options.workers
        self._infile = options.infile

        self._solver = solver
        self._cache = cachefc() if cachefc else None

        self._collection = []
        self._first = 0

    def _fillqueues(self, init_collect, set_collect, processq, resultq):
        # Read lines from input file and put into a shared queue
        file_pointer = open(self._infile)
        self._first, self._collection = init_collect(file_pointer)

        i = 0
        while True:
            i += 1
            line = file_pointer.readline().strip()
            if not line:
                # EOF
                break

            first = line.strip()
            if not first:
                break

            lines = [first]
            for line in set_collect(file_pointer, first):
                lines.append(line)

            processq.put((i, lines))

    def solve(self, set_collect=_scollect, init_collect=_collect):
        """
        Solve CodeJam input problem, reading lines from input file
        """
        threads = []

        # Start queues
        resultq = processing.Queue()
        processq = processing.Queue()

        self._fillqueues(init_collect, set_collect, processq, resultq)
        
        for i in xrange(self._workers):
            s = self._solver(processq, resultq, self._debug, self._cache,
                             self._first, self._collection)
            s.start()
            threads.append(s)

        for t in threads:
            t.join()

        results = []
        while True:
            try:
                results.append(resultq.get(block=False))
            except Empty:
                break

        if self._workers > 1:
            results.sort()

        fileout = open('%s.out' % self._infile, 'w')
        for i, res in results:
            case = 'Case #%d: %s' % (i, res)
            t.debug(case)
            fileout.write(case + '\n')

        fileout.close()
