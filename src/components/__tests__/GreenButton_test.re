open Jest;
open Expect;

let _ =

describe("GreenButton", () => {
  let action = Action.Add;
  let dispatch = _action => ();

  test("renders", () => {
    let tree = <GreenButton action dispatch />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });

  test("renders a class name", () => {
    let className = Styles.make(~color="rebeccapurple", ()) |> Styles.className;
    let tree = <GreenButton action className dispatch />
      |> ReactShallowRenderer.renderWithRenderer;

    expect(tree) |> toMatchSnapshot;
  });
});
