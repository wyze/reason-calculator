open Jest;
open Expect;

let _ =

describe "ButtonGroup" (fun _ => {
  test "renders" (fun _ => {
    let children = [ <div>(ReactRe.stringToElement "child")</div>, <span /> ];
    let tree = ButtonGroup.createElement ::children () |> Renderer.render;

    expect tree |> toMatchSnapshot;
  });
});
