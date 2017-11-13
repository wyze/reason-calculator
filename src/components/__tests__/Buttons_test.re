open Jest;
open Expect;

let _ =

describe("Buttons", () => {
  test("renders", () => {
    let dispatch = _action => ();
    let tree = <Buttons dispatch /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
