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

/* string -> string */
let flipNumber num => num |> Util.toFloat |> (*.) (-1.0) |> Util.toString;

/* Operation.model -> Operation.model */
let doPosNeg cur => {
  let { left, right, symbol }: Operation.model = cur;
  let ( left', right' ) = switch ( right, symbol ) {
    | ( "", Pending ) => ( flipNumber left, right )
    | ( "", _ ) => ( left, flipNumber left )
    | ( _, Equals ) => ( flipNumber left, flipNumber right )
    | ( _, _ ) => ( left, flipNumber right )
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
    | PosNeg => {
      operations: switch ( cur.symbol, cur.total ) {
        | ( Pending, 0.0 ) => state.operations
        | ( _, _ ) => [ doPosNeg cur ] @ old
      }
    }
    | _ => {
      operations: switch cur.symbol {
        | Pending
        | Equals => create @ state.operations
        | _ => create @ old
      }
    }
  };
};

let store = Reductive.Store.create ::reducer preloadedState::init ();
