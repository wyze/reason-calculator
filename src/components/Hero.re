let component = ReasonReact.statelessComponent("Hero");

let className: string =
  Styles.merge([
    Styles.make(
      ~background="#dedede",
      ~borderRadius="5px",
      ~display="block",
      ~padding="1em",
      ~marginBottom="4em",
      ~textAlign="center",
      ~width="30em",
      ()
    ) |> Styles.className,
    Styles.make(~width="35em", ()) |> Styles.small,
  ]);

let make = _children => {
  ...component,
  render: _self =>
    <div className>
      <Title />
      <Features />
    </div>
};
