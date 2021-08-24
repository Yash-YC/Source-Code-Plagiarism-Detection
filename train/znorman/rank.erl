-module(rank).

-export([start/2]).


start(In, Out) ->
    f:clear(Out),
    [_NumTestCases|Cases] = f:read(In),
    check(1, Cases, Out).

check(_Num, [], _Out) ->
    ok;
check(Num, [NString|Rest], Out) ->
    N = list_to_integer(NString),
    {Case, Cases} = lists:split(2*N-1, Rest),
    Solution = calc(lists:sort(Case)),
    f:write(Out, Num, Solution),
    check(Num + 1, Cases, Out).

calc(CaseStrings) ->
    Case = [[list_to_integer(Y) || Y <-string:tokens(X, " ")] || X <- CaseStrings],
    calc2(lists:sort(lists:flatten(Case)), []).

calc2([], Sol) ->
    lists:reverse([integer_to_list(X) ++ " " || X <- Sol]);
calc2([A, A | Rest], Sol) ->
    calc2(Rest, Sol);
calc2([A | Rest], Sol) ->
    calc2(Rest, [A|Sol]).

