open Jest;
open Expect;

let _ =

describe("operation", () => {
  test("create will create a model", () => {
    let { left, right, symbol, total }: Operation.model = Operation.create("2", "2", Action.Add, 4.0);
    let actual = ( left, right, symbol, total );
    let expected = ( "2", "2", Action.Add, 4.0 );

    expect(actual) |> toEqual(expected);
  });

  test("default returns empty model", () => {
    let { left, right, symbol, total }: Operation.model = Operation.default;
    let actual = ( left, right, symbol, total );
    let expected = ( "", "", Action.Pending, 0.0 );

    expect(actual) |> toEqual(expected);
  });

  test("createEquals returns equal record", () => {
    let model = Operation.create("2", "2", Action.Add, 4.0);
    let { left, right, symbol, total }: Operation.model = Operation.createEquals(model);
    let actual = ( left, right, symbol, total );
    let expected = ( "4", "4", Action.Equals, 4.0 );

    expect(actual) |> toEqual(expected);
  });

  test("tail returns the list except the first one", () => {
    let actual = Operation.tail([ 1, 2, 3, 4 ]);
    let expected = [ 2, 3, 4 ];

    expect(actual) |> toEqual(expected);
  });

  test("execute performs the infix operation", () => {
    let actual = Operation.execute((+.), "4", "4");
    let expected = 8.0;

    expect(actual) |> toEqual(expected);
  });

  test("head returns first item in the list", () => {
    let { left, right, symbol, total }: Operation.model = Operation.head([
      Operation.create("1", "", Action.Pending, 0.0),
      Operation.create("2", "", Action.Pending, 0.0),
      Operation.create("3", "", Action.Pending, 0.0),
      Operation.create("4", "", Action.Pending, 0.0),
    ]);
    let actual = ( left, right, symbol, total );
    let expected = ( "1", "", Action.Pending, 0.0 );

    expect(actual) |> toEqual(expected);
  });

  test("find returns first item matching the predicate", () => {
    let lst = [
      Operation.create("4", "", Action.Pending, 0.0),
      Operation.create("3", "", Action.Add, 0.0),
      Operation.create("2", "", Action.Pending, 0.0),
      Operation.create("1", "", Action.Add, 0.0),
    ];
    let { left, right, symbol, total }: Operation.model =
      Operation.find(lst, ({ symbol }) => symbol == Action.Add);
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "", Action.Add, 0.0 );

    expect(actual) |> toEqual(expected);
  });

  test("update handles Pending action properly", () => {
    let { left, right, symbol, total }: Operation.model =
      Operation.default |> Operation.update("3");
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "", Action.Pending, 3.0 );

    expect(actual) |> toEqual(expected);
  });

  test("update handles Add action properly", () => {
    let { left, right, symbol, total }: Operation.model =
      Operation.create("3", "", Action.Add, 3.0) |> Operation.update("3");
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "3", Action.Add, 6.0 );

    expect(actual) |> toEqual(expected);
  });

  test("update handles Multiply action properly", () => {
    let { left, right, symbol, total }: Operation.model =
      Operation.create("3", "", Action.Multiply, 3.0) |> Operation.update("3");
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "3", Action.Multiply, 9.0 );

    expect(actual) |> toEqual(expected);
  });

  test("getInput returns 0 for empty list", () => {
    let actual = Operation.getInput([]);
    let expected = "0";

    expect(actual) |> toEqual(expected);
  });

  test("getInput returns proper value for simple list", () => {
    let actual = [
      Operation.create("5", "", Action.Pending, 5.0),
    ] |> Operation.getInput;
    let expected = "5";

    expect(actual) |> toEqual(expected);
  });

  test("getInput returns proper value for complex list", () => {
    let actual = [
      Operation.create("14", "14", Action.Equals, 14.0),
      Operation.create("7", "2", Action.Multiply, 14.0),
      Operation.create("3", "4", Action.Add, 7.0),
      Operation.create("1", "2", Action.Add, 3.0),
    ] |> Operation.getInput;
    let expected = "14";

    expect(actual) |> toEqual(expected);
  });
});
