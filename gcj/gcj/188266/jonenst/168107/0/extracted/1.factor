! Copyright (C) 2009 Your name.
! See http://factorcode.org/license.txt for BSD license.
USING: math.parser memoize math sequences kernel io io.encodings.utf8 io.files splitting formatting ;
IN: gcj.1

: digits ( i base -- digits )
>base [ CHAR: 0 - ] map ;

: sum-of-digits-squared ( i base -- sum )
digits [ sq ] [ + ] map-reduce ;

: already-seen? ( seq base i -- ? )
swap drop swap member? ;

: add-to-list ( seq base i -- newseq base i )
swapd [ suffix ] keep swapd ;

: (happy?) ( seq base i -- ? )
3dup already-seen? 
[
   3drop f 
] [
    add-to-list
    dupd swap sum-of-digits-squared 
    dup 1 =
    [ 3drop t ] [ (happy?) ] if 
] if ;


MEMO: happy? ( base i -- ? )
[ { } ] dip swapd (happy?) ;

DEFER: all-happy?
: (all-happy?) ( bases i -- ? )
[ unclip ] dip 2dup happy? 
[ nip all-happy? ]
[ 3drop f ] if ;

: all-happy? ( bases i -- ? )
swap dup empty?
[ 2drop t ]
[ swap (all-happy?) ] if ;

: read-bases ( -- bases )
  readln " " split [ 10 base> ] map ;

: print-answer ( case# int -- )
[ 1 + ] dip
"Case #%d: %s\n" printf ;

: solve-case ( bases -- int )
2
[ 2dup all-happy? not ]
[ 1 + ] while nip ;

: do-case ( case# -- )
read-bases solve-case print-answer ;

: solve-file ( -- )
readln 10 base> iota
[ do-case ] each ;

: read-file ( file -- )
  utf8 [ solve-file ] with-file-reader ;

: write-answer ( file -- )
[ "work/gcj/1/results.out" utf8 ] dip [ read-file ] curry with-file-writer ;


