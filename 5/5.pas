program Problem5;

function GCD(a, b: Int64): Int64;
var
    t: Int64;
begin
    if a < 0 then a := -a;
    if b < 0 then b := -b;
    while b <> 0 do
    begin
        t := a mod b;
        a := b;
        b := t;
    end;
    GCD := a;
end;

function LCM(a, b: Int64): Int64;
begin
    if (a = 0) or (b = 0) then LCM := 0 else LCM := (a div GCD(a, b)) * b;
end;

function Solve(): Int64;
var
    i: Integer;
    ans: Int64;
begin
    ans := 1;
    for i := 2 to 20 do ans := LCM(ans, i);
end;

begin
    WriteLn('Smallest positive number evenly divisible by 1..20 is ', Solve);
end.

