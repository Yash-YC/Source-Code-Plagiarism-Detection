%% Author: jakob
%% Created: 12 sep 2009
%% Description: TODO: Add description to c1a_happy
-module(c1a_happy).

%%
%% Include files
%%

%%
%% Exported Functions
%%
-export([t/2]).

-compile(export_all).

%%
%% API Functions
%%

t(File, OutFile) ->
    {ok, B} = file:read_file(File),
    [_First | Lines] = string:tokens(binary_to_list(B), "\n"),
    Result = happy_lines(Lines, 1, []),
    file:write_file(OutFile, Result).

%%
%% Local Functions
%%

happy_lines([], _, Acc) ->
    Acc;
happy_lines([Line | Rest], I, Acc) ->
    Bases = [list_to_integer(N) || N <- string:tokens(Line, " ")],
    N = min_happy_num(Bases, 2),
    R = ["Case #", integer_to_list(I), ": ", integer_to_list(N), "\n"],
    happy_lines(Rest, I+1, [Acc | R]).

min_happy_num(Bases, N) ->
    case happy_bases(Bases, N) of
	true ->
	    N;
	false ->
	    min_happy_num(Bases, N+1)
    end.

happy_bases([], _N) ->
    true;
happy_bases([Base | Rest], N) ->
    case happy(N, Base) of
	true ->
	    happy_bases(Rest, N);
	false ->
	    false
    end.

happy(N, Base) ->
    happy(N, Base, []).

happy(N, Base, Sofar) ->
    case lists:member(N, Sofar) of
	true ->
	    false;
	false ->
	    D = digits_in_base(N, Base),
	    SS = lists:foldl(fun(E, A) -> E*E+A end, 0, D),
	    case SS of
		1 ->
		    true;
		_ ->
		    happy(SS, Base, [N | Sofar])
	    end
    end.

digits_in_base(0, _) ->
    [0];
digits_in_base(N, Base) ->
    digits_in_base(N, Base, []).

digits_in_base(0, _Base, Acc) ->
    Acc;
digits_in_base(N, Base, Acc) ->
    D = N rem Base,
    digits_in_base(N div Base, Base, [D | Acc]).


