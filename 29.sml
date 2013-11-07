structure iset = RedBlackSetFn(type ord_key = IntInf.int;
			       val compare = IntInf.compare);

fun enumerate (al, ah, bl, bh, S) =
    let
	fun iter (a, b, acc, S) =
	    if a>ah then acc
	    else if b>bh then iter(a+1, bl, acc, S)
	    else
		let
		    val num = IntInf.pow(a, b)
		in
		    case iset.find (fn x => x = num) S of
			NONE => iter(a, b+1, acc+1, iset.add(S, num))
		      | SOME _ => iter(a, b+1, acc, S)
		end
    in
	iter(al, bl, 0, S)
    end;

val ans = enumerate(2, 100, 2, 100, iset.empty);
