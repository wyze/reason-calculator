type model = {
  key: string,
  left: string,
  right: string,
  symbol: Action.model,
  total: float,
};

/* string -> string -> Action.model -> float -> model */
let create left right symbol total =>
  { key: Random.bits () |> string_of_int, left, right, symbol, total };

/* model */
let default = create "" "" Pending 0.0;

/* Shortcut to create an Action.Equals record */
/* model -> model */
let createEquals { total } => {
  let sTotal = Util.toString total;

  create sTotal sTotal Equals total;
};

/* Removes last element from the list and returns the rest of the list. */
/* list model -> list model */
let tail lst =>
  switch lst {
    | [ head, ...tail ] => tail
    | [] => lst
  };

/* ('a -> 'a -> a') -> string -> string -> float */
let execute infix left right => infix (Util.toFloat left) (Util.toFloat right);

/* list model -> model */
let head lst =>
  switch lst {
    | [ head, ...tail ] => head
    | [] => default
  };

/* list model -> (model -> bool) -> model */
let find lst predicate =>
  switch lst {
    | [] => default
    | _ => lst |> List.find predicate
  };

/* string -> model -> model */
let update input { left, right, symbol } => {
  let ( left', right' ) = switch ( input, symbol ) {
    | ( ".", Pending ) => ( Util.isFloat left ? left : left ^ input, right )
    | ( ".", _ ) => ( left, Util.isFloat right ? right : right ^ input )
    | ( _, Pending ) => ( left ^ input, right )
    | ( _, Equals ) => ( left, right )
    | ( _, _ ) => ( left, right ^ input )
  };

  execute (Action.toInfix symbol) left' right' |>
    create left' right' symbol;
};

/* list model -> string */
let getInput lst =>
  switch lst {
    | [] => "0"
    | _ => {
      let { left, right } = head lst;

      Util.strEmpty right ? left : right;
    }
  };
