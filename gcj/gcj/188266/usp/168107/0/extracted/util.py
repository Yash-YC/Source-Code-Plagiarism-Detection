
def repeatfn(f, n):
    for i in xrange(n):
        yield f()


class FileReader:

    def __init__(self, file):
        self.file = file

    def string(self):
        return self.file.readline().rstrip()

    def strings(self):
        return self.string().split()

    def int(self):
        return int(self.string())

    def ints(self):
        return map(int, self.strings())

    def istring(self, n):
        return repeatfn(self.string, n)

    def istrings(self, n):
        return repeatfn(self.strings, n)

    def iint(self, n):
        return repeatfn(self.int, n)

    def iints(self, n):
        return repeatfn(self.ints, n)

    def nstring(self, n):
        return list(self.istring(n))

    def nstrings(self, n):
        return list(self.istrings(n))

    def nint(self, n):
        return list(self.iint(n))

    def nints(self, n):
        return list(self.iints(n))

