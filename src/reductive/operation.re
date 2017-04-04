type model = {
  key: string,
  left: string,
  right: string,
  symbol: Action.model,
  total: int,
};

/* string -> string -> Action.model -> int -> model */
let create left right symbol total =>
  { key: Random.bits () |> Util.toString, left, right, symbol, total };

/* model */
let default = create "" "" Pending 0;

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

/* ('a -> 'a -> a') -> string -> string -> int */
let execute infix left right => infix (Util.toInt left) (Util.toInt right);

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
let update input { left, right, symbol } =>
  switch symbol {
    | Pending => create (left ^ input) right symbol (left ^ input |> Util.toInt)
    | Equals => create left right symbol (left |> Util.toInt)
    | _ =>
      execute (Action.toInfix symbol) left (right ^ input)
        |> create left (right ^ input) symbol
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
