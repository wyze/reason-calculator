open Jest;
open Expect;
open Action;

type tuple = { operations: list(( string, string, Action.model, float )) };

let toTuple = ({ operations }: Store.state): tuple => {
  operations: List.map(
    ({ Operation.left, right, symbol, total }) => ( left, right, symbol, total ),
    operations
  )
};

let reduce = (state, action) => Store.reducer(state, action);

let run = actions =>
  actions
    |> List.fold_left(reduce, Store.init)
    |> toTuple;

let _ =

describe("store", () => {
  test("returns initial state", () => {
    let actual = Reductive.Store.getState(Store.store);
    let expected = Store.init;

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Clear action", () => {
    let actual = [
      Input("1"),
      Add,
      Input("3"),
      Clear,
    ] |> run;
    let expected = { operations: [] };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Equals action", () => {
    let actual = [
      Input("1"),
      Add,
      Input("2"),
      Equals,
    ] |> run;
    let expected = {
      operations: [
        ( "3", "3", Equals, 3.0 ),
        ( "1", "2", Add, 3.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles double Equals action", () => {
    let actual = [
      Input("1"),
      Add,
      Input("2"),
      Equals,
      Equals,
    ] |> run;
    let expected = {
      operations: [
        ( "5", "5", Equals, 5.0 ),
        ( "3", "2", Add, 5.0 ),
        ( "3", "3", Equals, 3.0 ),
        ( "1", "2", Add, 3.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Input action with no previous state", () => {
    let actual = [
      Input("4"),
    ] |> run;
    let expected = {
      operations: [
        ( "4", "", Pending, 4.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Input action with Pending state", () => {
    let actual = [
      Input("1"),
      Input("4"),
    ] |> run;
    let expected = {
      operations: [
        ( "14", "", Pending, 14.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Input action with non-Pending state", () => {
    let actual = [
      Input("1"),
      Add,
      Input("4"),
    ] |> run;
    let expected = {
      operations: [
        ( "1", "4", Add, 5.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Input action after Equals state", () => {
    let actual = [
      Input("1"),
      Add,
      Input("2"),
      Equals,
      Input("4"),
    ] |> run;
    let expected = {
      operations: [
        ( "4", "", Pending, 4.0 ),
        ( "3", "3", Equals, 3.0 ),
        ( "1", "2", Add, 3.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Add action", () => {
    let actual = [
      Input("1"),
      Add,
    ] |> run;
    let expected = {
      operations: [
        ( "1", "", Add, 1.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles switch from Add to Subtract action", () => {
    let actual = [
      Input("1"),
      Add,
      Subtract,
    ] |> run;
    let expected = {
      operations: [
        ( "1", "", Subtract, 1.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles Add action after Equals action", () => {
    let actual = [
      Input("1"),
      Add,
      Input("1"),
      Equals,
      Add,
    ] |> run;
    let expected = {
      operations: [
        ( "2", "", Add, 2.0 ),
        ( "2", "2", Equals, 2.0 ),
        ( "1", "1", Add, 2.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  describe("PosNeg", () => {
    test("with initial state", () => {
      let actual = [
        PosNeg,
      ] |> run;
      let expected = { operations: [] };

      expect(actual) |> toEqual(expected);
    });

    test("with Pending state", () => {
      let actual = [
        Input("4"),
        PosNeg,
      ] |> run;
      let expected = {
        operations: [
          ( "-4", "", Pending, -4.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("when total would be 0", () => {
      let actual = [
        Input("5"),
        Subtract,
        Input("5"),
        PosNeg,
      ] |> run;
      let expected = {
        operations: [
          ( "5", "-5", Subtract, 10.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("with no right value", () => {
      let actual = [
        Input("4"),
        Add,
        PosNeg,
      ] |> run;
      let expected = {
        operations: [
          ( "4", "-4", Add, 0.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("with non-Pending state", () => {
      let actual = [
        Input("4"),
        Add,
        Input("2"),
        PosNeg,
      ] |> run;
      let expected = {
        operations: [
          ( "4", "-2", Add, 2.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("handles sequence: PosNeg -> Equals -> Equals", () => {
      let actual = [
        Input("5"),
        Multiply,
        Input("3"),
        PosNeg,
        Equals,
        Equals,
      ] |> run;
      let expected = {
        operations: [
          ( "45", "45", Equals, 45.0 ),
          ( "-15", "-3", Multiply, 45.0 ),
          ( "-15", "-15", Equals, -15.0 ),
          ( "5", "-3", Multiply, -15.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("handles sequence: Equals -> PosNeg -> Equals", () => {
      let actual = [
        Input("5"),
        Multiply,
        Input("3"),
        PosNeg,
        Equals,
        PosNeg,
        Equals,
      ] |> run;
      let expected = {
        operations: [
          ( "-45", "-45", Equals, -45.0 ),
          ( "15", "-3", Multiply, -45.0 ),
          ( "15", "15", Equals, 15.0 ),
          ( "5", "-3", Multiply, -15.0 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });
  });

  test("reducer handles decimals", () => {
    let actual = [
      Input("5"),
      Input("."),
      Input("3"),
      Add,
      Input("4"),
      Input("."),
      Input("7"),
      Equals,
    ] |> run;
    let expected = {
      operations: [
        ( "10", "10", Equals, 10.0 ),
        ( "5.3", "4.7", Add, 10.0 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  test("reducer handles double decimals", () => {
    let actual = [
      Input("2"),
      Input("."),
      Input("."),
      Input("3"),
      Add,
      Input("2"),
      Input("."),
      Input("7"),
      Input("."),
      Input("5"),
      Equals,
    ] |> run;
    let expected = {
      operations: [
        ( "5.05", "5.05", Equals, 5.05 ),
        ( "2.3", "2.75", Add, 5.05 ),
      ]
    };

    expect(actual) |> toEqual(expected);
  });

  describe("Percent", () => {
    test("with initial state", () => {
      let actual = [
        Percent,
      ] |> run;
      let expected = { operations: [] };

      expect(actual) |> toEqual(expected);
    });

    test("with Pending state", () => {
      let actual = [
        Input("4"),
        Percent,
      ] |> run;
      let expected = {
        operations: [
          ( "0.04", "", Pending, 0.04 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("with no right value", () => {
      let actual = [
        Input("4"),
        Add,
        Percent,
      ] |> run;
      let expected = {
        operations: [
          ( "4", "0.04", Add, 4.04 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("with non-Pending state", () => {
      let actual = [
        Input("4"),
        Add,
        Input("2"),
        Percent,
      ] |> run;
      let expected = {
        operations: [
          ( "4", "0.02", Add, 4.02 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("handles sequence: Percent -> Equals -> Equals", () => {
      let actual = [
        Input("5"),
        Multiply,
        Input("5"),
        Input("0"),
        Percent,
        Equals,
        Equals,
      ] |> run;
      let expected = {
        operations: [
          ( "1.25", "1.25", Equals, 1.25 ),
          ( "2.5", "0.5", Multiply, 1.25 ),
          ( "2.5", "2.5", Equals, 2.5 ),
          ( "5", "0.5", Multiply, 2.5 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });

    test("handles sequence: Equals -> Percent -> Equals", () => {
      let actual = [
        Input("5"),
        Multiply,
        Input("5"),
        Input("0"),
        Percent,
        Equals,
        Percent,
        Equals,
      ] |> run;
      let expected = {
        operations: [
          ( "0.0125", "0.0125", Equals, 0.0125 ),
          ( "0.025", "0.5", Multiply, 0.0125 ),
          ( "0.025", "0.025", Equals, 0.025 ),
          ( "5", "0.5", Multiply, 2.5 ),
        ]
      };

      expect(actual) |> toEqual(expected);
    });
  });
});
