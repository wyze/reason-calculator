type model =
  | Add
  | Clear
  | Divide
  | Equals
  | Pending
  | Input(string)
  | Multiply
  | Subtract
  | PosNeg
  | Percent;

/* model -> (float -> float -> float) */
let toInfix = action =>
  switch action {
    | Add => (+.)
    | Divide => (/.)
    | Multiply => (*.)
    | Subtract => (-.)
    /* noop function */
    | _ => ((left, _) => left)
  };

/* model -> string */
let toText = action =>
  switch action {
    | Add => "+"
    | Clear => "C"
    | Divide => "&divide;"
    | Equals => "="
    | Multiply => "&times;"
    | Subtract => "&minus;"
    | PosNeg => "+/&minus;"
    | Percent => "%"
    | _ => ""
  };
