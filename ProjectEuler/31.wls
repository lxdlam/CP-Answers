c := {200, 100, 50, 20, 10, 5, 2, 1};
f[x_] := 1/Product[(1 - x^c[[i]]), {i, Length[c]}];
Print[Coefficient[Series[f[x], {x, 0, 200}], x^200] // AbsoluteTiming]