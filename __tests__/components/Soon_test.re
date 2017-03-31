open Jest;
open Expect;

let _ =

describe "Soon" (fun _ => {
  test "renders" (fun _ => {
    let tree = Soon.createElement children::[] () |> Renderer.render;

    (expect tree) |> toMatchSnapshot;
  });
});
