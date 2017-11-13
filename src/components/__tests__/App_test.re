open Jest;
open Expect;

let _ =

describe("App", () => {
  test("renders", () => {
    let dispatch = _action => ();
    let state = Store.init;
    let tree = <App dispatch state /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
