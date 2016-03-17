{ Copyright (c) 2016 Imed Eddine Nezzar <imad.eddine.nezzar[at]gmail.com> }
program magic_matrix;
const SIZE = 3;
var arr : array[1..SIZE] of array[1..SIZE] of integer;
    sum, dl, dr, r, c, i, j : integer;
    magic : boolean;


begin
    writeln('Enter values: ');
    for i := 1 to SIZE do
        for j := 1 to SIZE do
            read(arr[i][j]);

    writeln('Matrix:');
    for i := 1 to SIZE do begin
        for j := 1 to SIZE do
            write(arr[i][j], ' ');
        writeln;
    end;
    dl := 0;
    dr := 0;
    sum := -1;
    magic := true;
    for i := 1 to SIZE do begin
        r := 0;
        c := 0;
        dl += arr[i][i];
        dr += arr[i][SIZE - i];
        for j := 1 to SIZE do begin
            r += arr[i][j];
            c += arr[j][i];
        end;
        if (sum = -1) then sum := r;
        if (r <> c) or (c <> sum) then begin
            magic := false;
            break;
        end;
    end;

    if (magic = true) and (dl = dr) and (dr = sum) then
        writeln('Is a magic matrix.')
    else
        writeln('Is not a magic matrix.');

end.
