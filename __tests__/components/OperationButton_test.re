open Jest;
open Expect;

let _ =

describe "OperationButton" (fun _ => {
  test "renders" (fun _ => {
    let action = Action.Add;
    let dispatch = fun _ => ();
    let tree = OperationButton.createElement ::action ::dispatch children::[] () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });

  test "renders a class name" (fun _ => {
    let action = Action.Add;
    let className = Styles.make color::"rebeccapurple" () |> Styles.className;
    let dispatch = fun _ => ();
    let tree = OperationButton.createElement ::action ::className ::dispatch children::[] ()
      |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
