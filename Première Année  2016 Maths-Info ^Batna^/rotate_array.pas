program rotate_array;
const n = 10;
var T : array[1..n] of integer;
    i, s, e, tmp, r : integer;
begin
    (* reading array values *)
    for i := 1 to n do begin
        write('Enter T[', i, ']: '); read(T[i]);
    end;

    (* reading rotate value *)
    repeat
        write('Enter rotate value: '); read(r);
    until (r >= 1) and (r <= 10);

    (* printing array values *)
    for i := 1 to n do write(T[i], ' '); writeln;

    (* rotating array by r (left rotate) *)
    r := n - r - 1;

    s := 1;
    e := r;
    while (s < e) do begin
        tmp := T[s];
        T[s] := T[e];
        T[e] := tmp;
        s += 1;
        e -= 1;
    end;

    s := r + 1;
    e := n;
    while (s < e) do begin
        tmp := T[s];
        T[s] := T[e];
        T[e] := tmp;
        s += 1;
        e -= 1;
    end;

    s := 1;
    e := n;
    while (s < e) do begin
        tmp := T[s];
        T[s] := T[e];
        T[e] := tmp;
        s += 1;
        e -= 1;
    end;

    (* printing array values *)
    for i := 1 to n do write(T[i], ' '); writeln;
end.
