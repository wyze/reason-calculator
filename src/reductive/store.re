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
  let prev = Operation.create (Util.toString cur.total) right symbol 0 |> Operation.update "";

  switch cur.symbol {
    | Equals => [ Operation.createEquals prev, prev ]
    | _ => [ Operation.createEquals cur ]
  };
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
