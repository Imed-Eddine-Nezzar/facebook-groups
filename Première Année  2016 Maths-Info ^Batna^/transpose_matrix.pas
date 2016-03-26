program transpose;
const n = 3;
var
    T1, T2 : array[1..n] of array[1..n] of integer;
    i, j, t : integer;
(* main *)
begin
    (* getting matrix T1 elements *)
    for i := 1 to n do begin
        for j := 1 to n do begin
            write('Enter cell T[',i,']', '[', j,']: ');
            read(T1[i][j]);
        end;
    end;
    (* transposing matrix T1 elements into T2 *)
    for i := 1 to n do
        for j := 1 to n do
            T2[i][j] := T1[j][i];
    (* printing matrix T1 elements *)
    writeln('T: ');
    for i := 1 to n do begin
        for j := 1 to n do begin
            write(T1[i][j], ' ');
        end;
        writeln();
    end;
    (* printing matrix T2 elements *)
    writeln('T transposed: ');
    for i := 1 to n do begin
        for j := 1 to n do begin
            write(T2[i][j], ' ');
        end;
        writeln();
    end;
    (* transposing matrix T1 elements inplace *)
    writeln('T transposed: ');
    for i := 1 to n do
        for j := i+1 to n do begin
            t := T1[i][j];
            T1[i][j] := T1[j][i];
            T1[j][i] := t;
        end;
    (* printing matrix T1 elements *)
    writeln('T transposed inplace: ');
    for i := 1 to n do begin
        for j := 1 to n do begin
            write(T1[i][j], ' ');
        end;
        writeln();
    end;
end.
