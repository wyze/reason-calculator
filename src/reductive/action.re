type model =
  | Add
  | Clear
  | Divide
  | Equals
  | Pending
  | Input string
  | Multiply
  | Subtract
  | PosNeg;

/* model -> (float -> float -> float) */
let toInfix action =>
  switch action {
    | Add => (+.)
    | Divide => (/.)
    | Multiply => (*.)
    | Subtract => (-.)
    /* noop function */
    | _ => (fun left _ => left)
  };

/* model -> string */
let toText action =>
  switch action {
    | Add => "+"
    | Clear => "Clear"
    | Divide => "&divide;"
    | Equals => "="
    | Multiply => "&times;"
    | Subtract => "&minus;"
    | PosNeg => "+/&minus;"
    | _ => ""
  };
