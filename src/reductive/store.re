type action = Action.model;

type state = {
  operations: list Operation.model
};

let init = {
  operations: []
};

/* list Operation.model -> Operation.model -> list Operation.model */
let addEquals lst (cur: Operation.model) => {
  let { Operation.right, symbol } = Operation.findLast lst (fun { symbol } => symbol != Equals);
  let prev = Operation.create (Util.toString cur.total) right symbol 0 |> Operation.update "";

  switch cur.symbol {
    | Equals => [ prev, Operation.createEquals prev ]
    | _ => [ Operation.createEquals cur ]
  };
};

/* state -> action -> state */
let reducer state action => {
  let cur = Operation.last state.operations;
  let old = Operation.dropLastOne state.operations;
  let create = [ Operation.create (Util.toString cur.total) "" action cur.total ];

  switch action {
    | Clear => init
    | Equals => {
      operations: state.operations @ (addEquals state.operations cur)
    }
    | Input input => {
      operations: switch cur.symbol {
        | Equals => state.operations @ [ Operation.default |> Operation.update input ]
        | _ => old @ [ cur |> Operation.update input ]
      }
    }
    | Pending => state
    | _ => {
      operations: switch cur.symbol {
        | Pending
        | Equals => state.operations @ create
        | _ => old @ create
      }
    }
  };
};

let store = Reductive.Store.create ::reducer preloadedState::init ();
