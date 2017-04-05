open Jest;
open Expect;

type tuple = { operations: list ( string, string, Action.model, float ) };
let toTuple ({ operations }: Store.state): tuple => {
  operations: List.map
    (fun { Operation.left, right, symbol, total } => ( left, right, symbol, total ))
    operations
};

let _ =

describe "store" (fun _ => {
  test "returns initial state" (fun _ => {
    let actual = Reductive.Store.getState Store.store;
    let expected = Store.init;

    expect actual |> toEqual expected;
  });

  test "reducer handles Clear action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.default,
      ]
    };
    let actual = Store.reducer state Action.Clear;
    let expected: Store.state = { operations: [] };

    expect actual |> toEqual expected;
  });

  test "reducer handles Equals action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "2" Action.Add 3.0,
      ]
    };
    let actual = Store.reducer state Action.Equals |> toTuple;
    let expected = {
      operations: [
        ( "3", "3", Action.Equals, 3.0 ),
        ( "1", "2", Action.Add, 3.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles double Equals action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "3" "3" Action.Equals 3.0,
        Operation.create "1" "2" Action.Add 3.0,
      ]
    };
    let actual = Store.reducer state Action.Equals |> toTuple;
    let expected = {
      operations: [
        ( "5", "5", Action.Equals, 5.0 ),
        ( "3", "2", Action.Add, 5.0 ),
        ( "3", "3", Action.Equals, 3.0 ),
        ( "1", "2", Action.Add, 3.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Input action with no previous state" (fun _ => {
    let state: Store.state = Store.init;
    let actual = Store.reducer state (Action.Input "4") |> toTuple;
    let expected = {
      operations: [
        ( "4", "", Action.Pending, 4.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Input action with Pending state" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "" Action.Pending 1.0,
      ]
    };
    let actual = Store.reducer state (Action.Input "4") |> toTuple;
    let expected = {
      operations: [
        ( "14", "", Action.Pending, 14.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Input action with non-Pending state" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "" Action.Add 1.0,
      ]
    };
    let actual = Store.reducer state (Action.Input "4") |> toTuple;
    let expected = {
      operations: [
        ( "1", "4", Action.Add, 5.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Input action after Equals state" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "3" "3" Action.Equals 3.0,
        Operation.create "1" "2" Action.Add 3.0,
      ]
    };
    let actual = Store.reducer state (Action.Input "4") |> toTuple;
    let expected = {
      operations: [
        ( "4", "", Action.Pending, 4.0 ),
        ( "3", "3", Action.Equals, 3.0 ),
        ( "1", "2", Action.Add, 3.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Pending action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "2" Action.Add 3.0,
      ]
    };
    let actual = Store.reducer state Action.Pending |> toTuple;
    let expected = {
      operations: [
        ( "1", "2", Action.Add, 3.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  /* TODO: Review behavior, might not be right */
  test "reducer handles Add action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "" Action.Pending 1.0,
      ]
    };
    let actual = Store.reducer state Action.Add |> toTuple;
    let expected = {
      operations: [
        ( "1", "", Action.Add, 1.0 ),
        ( "1", "", Action.Pending, 1.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles switch from Add to Subtract action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "1" "" Action.Add 1.0,
        Operation.create "1" "" Action.Pending 1.0,
      ]
    };
    let actual = Store.reducer state Action.Subtract |> toTuple;
    let expected = {
      operations: [
        ( "1", "", Action.Subtract, 1.0 ),
        ( "1", "", Action.Pending, 1.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Add action after Equals action" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "2" "2" Action.Equals 2.0,
        Operation.create "1" "1" Action.Add 2.0,
        Operation.create "1" "" Action.Pending 1.0,
      ]
    };
    let actual = Store.reducer state Action.Add |> toTuple;
    let expected = {
      operations: [
        ( "2", "", Action.Add, 2.0 ),
        ( "2", "2", Action.Equals, 2.0 ),
        ( "1", "1", Action.Add, 2.0 ),
        ( "1", "", Action.Pending, 1.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg action with initial state" (fun _ => {
    let state: Store.state = Store.init;
    let actual = Store.reducer state Action.PosNeg;
    let expected: Store.state = { operations: [] };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg action with Pending state" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "4" "" Action.Pending 4.0,
      ]
    };
    let actual = Store.reducer state Action.PosNeg |> toTuple;
    let expected = {
      operations: [
        ( "-4", "", Action.Pending, -4.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg action when total would be 0" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "5" "5" Action.Subtract 0.0,
      ]
    };
    let actual = Store.reducer state Action.PosNeg |> toTuple;
    let expected = {
      operations: [
        ( "5", "-5", Action.Subtract, 10.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg action with no right value" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "4" "" Action.Add 4.0,
      ]
    };
    let actual = Store.reducer state Action.PosNeg |> toTuple;
    let expected = {
      operations: [
        ( "4", "-4", Action.Add, 0.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg action with non-Pending state" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "4" "2" Action.Add 6.0,
      ]
    };
    let actual = Store.reducer state Action.PosNeg |> toTuple;
    let expected = {
      operations: [
        ( "4", "-2", Action.Add, 2.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles PosNeg -> Equals -> Equals" (fun _ => {
    let state: Store.state = {
      operations: [
        Operation.create "-15" "-15" Action.Equals (-15.0),
        Operation.create "5" "-3" Action.Multiply (-15.0),
      ]
    };
    let actual = Store.reducer state Action.Equals |> toTuple;
    let expected = {
      operations: [
        ( "45", "45", Action.Equals, 45.0 ),
        ( "-15", "-3", Action.Multiply, 45.0 ),
        ( "-15", "-15", Action.Equals, -15.0 ),
        ( "5", "-3", Action.Multiply, -15.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });

  test "reducer handles Equals -> PosNeg -> Equals" (fun _ => {
    let equals: Store.state = {
      operations: [
        Operation.create "-15" "-15" Action.Equals (-15.0),
        Operation.create "5" "-3" Action.Multiply (-15.0),
      ]
    };
    let state = Store.reducer equals Action.PosNeg;
    let actual = Store.reducer state Action.Equals |> toTuple;
    let expected = {
      operations: [
        ( "-45", "-45", Action.Equals, -45.0 ),
        ( "15", "-3", Action.Multiply, -45.0 ),
        ( "15", "15", Action.Equals, 15.0 ),
        ( "5", "-3", Action.Multiply, -15.0 ),
      ]
    };

    expect actual |> toEqual expected;
  });
});
