open Jest;
open Expect;

let _ =

describe "Title" (fun _ => {
  test "renders" (fun _ => {
    let tree = Title.createElement children::[] () |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
