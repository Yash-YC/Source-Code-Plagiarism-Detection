-module(last_word).

-export([start/2]).


start(In, Out) ->
    f:clear(Out),
    [_NumTestCases|Cases] = f:read(In),
    check(1, Cases, Out).

check(_Num, [], _Out) ->
    ok;
check(Num, [Case|Cases], Out) ->
    Solution = calc(Case, [""]),
    f:write(Out, Num, Solution),
    check(Num + 1, Cases, Out).

calc([], [Last]) ->
    Last;
calc([A|Case], AllMutations) ->
    NextMutationsA = [[A|Mutation] || Mutation <- AllMutations],
    NextMutationsB = [Mutation ++ [A] || Mutation <- AllMutations],
    calc(Case, [get_last(NextMutationsA ++ NextMutationsB)]).

get_last(List) ->
    hd(lists:reverse(lists:sort(List))).

