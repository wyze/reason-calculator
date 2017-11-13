open Jest;
open Expect;

let _ =

describe("Title", () => {
  test("renders", () => {
    let tree = <Title /> |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
