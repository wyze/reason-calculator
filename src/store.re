type action =
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

type operation = {
  action,
  left: string,
  right: string,
  total: float,
};

type state = list(operation);

module Operation = {
  let default = {left: "", right: "", action: Pending, total: 0.};

  let make = () => default;

  let toInfix = action =>
    switch (action) {
    | Add => (+.)
    | Divide => (/.)
    | Multiply => ( *. )
    | Subtract => (-.)
    /* noop function */
    | _ => ((left, _) => left)
    };

  let strEmpty = str => String.length(str) == 0;
  let isFloat = str => Js.String.includes(".", str);
  let toFloat = str => strEmpty(str) ? 0. : float_of_string(str);
  let toString = flt => {
    let str = Js.Float.toString(flt);

    Js.String.endsWith(".", str) ? Js.String.replace(".", "", str) : str;
  };

  let find = (lst, predicate) =>
    switch (lst) {
    | [] => default
    | _ => lst |> List.find(predicate)
    };

  let multiply = (factor, num) =>
    num |> toFloat |> ( *. )(factor) |> toString;

  let execute = (infix, left, right) =>
    infix(toFloat(left), toFloat(right));

  let update = (input, {left, right, action}) => {
    let (left', right') =
      switch (input, action) {
      | (".", Pending) => (isFloat(left) ? left : left ++ input, right)
      | (".", _) => (left, isFloat(right) ? right : right ++ input)
      | (_, Pending) => (left ++ input, right)
      | (_, Equals) => (left, right)
      | (_, _) => (left, right ++ input)
      };

    {
      left: left',
      right: right',
      action,
      total: action->toInfix->execute(left', right'),
    };
  };

  let createEquals = ({total}) => {
    let sTotal = toString(total);

    {left: sTotal, right: sTotal, action: Equals, total};
  };

  let addEquals = (lst, cur) => {
    let {right, action} = find(lst, ({action}) => action != Equals);
    let prev =
      update("", {left: cur.total->toString, right, action, total: 0.});

    switch (cur.action) {
    | Equals => [createEquals(prev), prev]
    | _ => [createEquals(cur)]
    };
  };

  let doOperation = (factor, {left, right, action}) => {
    let op = multiply(factor);
    let (left', right') =
      switch (right, action) {
      | ("", Pending) => (op(left), right)
      | ("", _) => (left, op(left))
      | (_, Equals) => (op(left), op(right))
      | (_, _) => (left, op(right))
      };

    update("", {left: left', right: right', action, total: 0.});
  };
};

let context: React.Context.t((state, action => unit)) = React.createContext(([], _ => ()));

module Provider = {
  let make = context->React.Context.provider;

  [@bs.obj]
  external makeProps:
    (~value: 'a, ~children: React.element, ~key: string=?, unit) =>
    {
      .
      "value": 'a,
      "children": React.element,
    } =
    "";
};

let reducer = (state, action) => {
  let ({total} as current, old) =
    switch (state) {
    | [hd, ...tl] => (hd, tl)
    | [] => (Operation.default, state)
    };

  switch (action) {
  | Clear => []
  | Equals => Operation.addEquals(state, current) @ state
  | Input(input) =>
    switch (current.action) {
    | Equals => [Operation.default |> Operation.update(input)] @ state
    | _ => [current |> Operation.update(input)] @ old
    }
  | Pending => state
  | Percent
  | PosNeg =>
    switch (action, current.action, total) {
    | (_, Pending, 0.) => state
    | (Percent, _, _) => [Operation.doOperation(0.01, current)] @ old
    | (PosNeg, _, _) => [Operation.doOperation(-1., current)] @ old
    | (_, _, _) => state /* Prevent warning of possible value */
    }
  | _ => [
      {left: total->Operation.toString, right: "", action, total},
      ...switch (current.action) {
         | Equals => state
         | _ => old
         },
    ]
  };
};

let useDisplay = () => {
  let (operations, _) = React.useContext(context);

  switch (operations) {
  | [] => "0"
  | ops =>
    let {left, right} = List.hd(ops);

    Operation.strEmpty(right) ? left : right;
  };
};

let useAddOperation = () => {
  let (_, dispatch) = React.useContext(context);

  action => action->dispatch;
};
