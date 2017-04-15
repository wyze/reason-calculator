type action = Action.model;

type state = {
  operations: list Operation.model
};

let init = {
  operations: []
};

/* list Operation.model -> Operation.model -> list Operation.model */
let addEquals lst (cur: Operation.model) => {
  let { Operation.right, symbol } = Operation.find lst (fun { symbol } => symbol != Equals);
  let prev = Operation.create (Util.toString cur.total) right symbol 0.0 |> Operation.update "";

  switch cur.symbol {
    | Equals => [ Operation.createEquals prev, prev ]
    | _ => [ Operation.createEquals cur ]
  };
};

/* float -> string -> string */
let multiply factor num => num |> Util.toFloat |> (*.) factor |> Util.toString;

/* float -> Operation.model -> Operation.model */
let doOperation factor cur => {
  let op = multiply factor;
  let { left, right, symbol }: Operation.model = cur;
  let ( left', right' ) = switch ( right, symbol ) {
    | ( "", Pending ) => ( op left, right )
    | ( "", _ ) => ( left, op left )
    | ( _, Equals ) => ( op left, op right )
    | ( _, _ ) => ( left, op right )
  };

  Operation.create left' right' symbol 0.0 |> Operation.update "";
};

/* state -> action -> state */
let reducer state action => {
  let cur = Operation.head state.operations;
  let old = Operation.tail state.operations;
  let create = [ Operation.create (Util.toString cur.total) "" action cur.total ];

  switch action {
    | Clear => init
    | Equals => {
      operations: (addEquals state.operations cur) @ state.operations
    }
    | Input input => {
      operations: switch cur.symbol {
        | Equals => [ Operation.default |> Operation.update input ] @ state.operations
        | _ => [ cur |> Operation.update input ] @ old
      }
    }
    | Pending => state
    | Percent
    | PosNeg => {
      operations: switch ( action, cur.symbol, cur.total ) {
        | ( _, Pending, 0.0 ) => state.operations
        | ( Percent, _, _ ) => [ doOperation 0.01 cur ] @ old
        | ( PosNeg, _, _ ) => [ doOperation (-1.0) cur ] @ old
      }
    }
    | _ => {
      operations: switch cur.symbol {
        | Equals => create @ state.operations
        | _ => create @ old
      }
    }
  };
};

let store = Reductive.Store.create ::reducer preloadedState::init ();
