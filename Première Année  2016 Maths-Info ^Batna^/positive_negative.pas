program pos_neg;
const n = 3;
var T : array[1..n] of array[1..n] of integer;
    R : array[1..n * n] of integer;
    i, j, s, e : integer;

begin
    (* filling the matrix *)
    for i := 1 to n do begin
        for j := 1 to n do begin
            write('Enter T[', i, ']', '[', j, ']: ');
            read(T[i][j]);
        end;
    end;

    (* seperating positive and negative values *)
    s := 1;
    e := n * n;
    for i := 1 to n do begin
        for j := 1 to n do begin
            if (T[i][j] < 0) then begin
                R[e] := T[i][j];
                e -= 1;
            end
            else begin
                R[s] := T[i][j];
                s += 1;
            end;
        end;
    end;

    (* printing the matrix flat *)
    for i := 1 to n * n do write(R[i], ' ');
    writeln;
end.
