open Jest;
open Expect;

let _ =

describe("Hero", () => {
  test("renders", () => {
    let tree = <Hero /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
