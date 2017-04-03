open Jest;
open Expect;

let _ =

describe "operation" (fun _ => {
  test "create will create a model" (fun _ => {
    let { left, right, symbol, total }: Operation.model = Operation.create "2" "2" Action.Add 4;
    let actual = ( left, right, symbol, total );
    let expected = ( "2", "2", Action.Add, 4 );

    expect actual |> toEqual expected;
  });

  test "default returns empty model" (fun _ => {
    let { left, right, symbol, total }: Operation.model = Operation.default;
    let actual = ( left, right, symbol, total );
    let expected = ( "", "", Action.Pending, 0 );

    expect actual |> toEqual expected;
  });

  test "createEquals returns equal record" (fun _ => {
    let model = Operation.create "2" "2" Action.Add 4;
    let { left, right, symbol, total }: Operation.model = Operation.createEquals model;
    let actual = ( left, right, symbol, total );
    let expected = ( "4", "4", Action.Equals, 4 );

    expect actual |> toEqual expected;
  });

  test "tail returns the list except the first one" (fun _ => {
    let actual = Operation.tail [ 1, 2, 3, 4 ];
    let expected = [ 2, 3, 4 ];

    expect actual |> toEqual expected;
  });

  test "execute performs the infix operation" (fun _ => {
    let actual = Operation.execute (+) "4" "4";
    let expected = 8;

    expect actual |> toEqual expected;
  });

  test "head returns first item in the list" (fun _ => {
    let { left, right, symbol, total }: Operation.model = Operation.head [
      Operation.create "1" "" Action.Pending 0,
      Operation.create "2" "" Action.Pending 0,
      Operation.create "3" "" Action.Pending 0,
      Operation.create "4" "" Action.Pending 0,
    ];
    let actual = ( left, right, symbol, total );
    let expected = ( "1", "", Action.Pending, 0 );

    expect actual |> toEqual expected;
  });

  test "find returns first item matching the predicate" (fun _ => {
    let lst = [
      Operation.create "4" "" Action.Pending 0,
      Operation.create "3" "" Action.Add 0,
      Operation.create "2" "" Action.Pending 0,
      Operation.create "1" "" Action.Add 0,
    ];
    let { left, right, symbol, total }: Operation.model =
      Operation.find lst (fun { symbol } => Pervasives.(symbol == Action.Add));
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "", Action.Add, 0 );

    expect actual |> toEqual expected;
  });

  test "update handles Pending action properly" (fun _ => {
    let { left, right, symbol, total }: Operation.model =
      Operation.default |> Operation.update "3";
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "", Action.Pending, 3 );

    expect actual |> toEqual expected;
  });

  test "update handles Add action properly" (fun _ => {
    let { left, right, symbol, total }: Operation.model =
      Operation.create "3" "" Action.Add 3 |> Operation.update "3";
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "3", Action.Add, 6 );

    expect actual |> toEqual expected;
  });

  test "update handles Multiply action properly" (fun _ => {
    let { left, right, symbol, total }: Operation.model =
      Operation.create "3" "" Action.Multiply 3 |> Operation.update "3";
    let actual = ( left, right, symbol, total );
    let expected = ( "3", "3", Action.Multiply, 9 );

    expect actual |> toEqual expected;
  });

  test "getInput returns 0 for empty list" (fun _ => {
    let actual = Operation.getInput [];
    let expected = "0";

    expect actual |> toEqual expected;
  });

  test "getInput returns proper value for simple list" (fun _ => {
    let actual = [
      Operation.create "5" "" Action.Pending 5,
    ] |> Operation.getInput;
    let expected = "5";

    expect actual |> toEqual expected;
  });

  test "getInput returns proper value for complex list" (fun _ => {
    let actual = [
      Operation.create "14" "14" Action.Equals 14,
      Operation.create "7" "2" Action.Multiply 14,
      Operation.create "3" "4" Action.Add 7,
      Operation.create "1" "2" Action.Add 3,
    ] |> Operation.getInput;
    let expected = "14";

    expect actual |> toEqual expected;
  });
});
