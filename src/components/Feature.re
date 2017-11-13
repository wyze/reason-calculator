let component = ReasonReact.statelessComponent("Feature");

type emoji = Checkmark | Soon;

let className: string =
  Styles.merge([
    Styles.make(
      ~alignItems="center",
      ~display="flex",
      ~flexBasis="40%",
      ~height="2em",
      ()
    ) |> Styles.className,
    Styles.make(~flexBasis="35%", ()) |> Styles.small,
  ]);

let getEmoji = emoji =>
  switch emoji {
    | Checkmark => <Checkmark />
    | Soon => <Soon />
  };

let make = (~emoji, ~text, _children) => {
  ...component,
  render: _self =>
    <div className>
      {getEmoji(emoji)}
      <h3>{ReasonReact.stringToElement(text)}</h3>
    </div>
};
