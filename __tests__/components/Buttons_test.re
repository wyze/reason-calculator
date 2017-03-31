open Jest;
open Expect;

let _ =

describe "Buttons" (fun _ => {
  test "renders" (fun _ => {
    let dispatch = fun _ => ();
    let tree = Buttons.createElement ::dispatch children::[] () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
