open Jest;
open Expect;

let _ =

describe("Svg", () => {
  test("renders", () => {
    let tree = (
      <Svg>
        <g />
        <path />
      </Svg>
    ) |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
