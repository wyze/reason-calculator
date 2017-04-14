open Jest;
open Expect;

let _ =

describe "Soon" (fun _ => {
  test "renders" (fun _ => {
    let tree = Soon.createElement children::[] () |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });
});
