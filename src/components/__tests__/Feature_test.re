open Jest;
open Expect;

let _ =

describe("Feature", () => {
  test("renders checkmark emoji", () => {
    let tree = <Feature emoji=Feature.Checkmark text="A feature" />
    |> ReactShallowRenderer.renderWithRenderer;

  expect(tree) |> toMatchSnapshot
});

  test("renders soon emoji", () => {
    let tree = <Feature emoji=Feature.Soon text="A feature" />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
