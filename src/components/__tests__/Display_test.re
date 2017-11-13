open Jest;
open Expect;

let _ =

describe("Display", () => {
  test("renders", () => {
    let tree = <Display output="42" /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
