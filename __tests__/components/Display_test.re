open Jest;
open Expect;

let _ =

describe "Display" (fun _ => {
  test "renders" (fun _ => {
    let output = "42";
    let tree = Display.createElement ::output children::[] () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
