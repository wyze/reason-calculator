let component = ReasonReact.statelessComponent("Svg");

let viewBox: string = "0 0 64 64";
let className: string =
  Styles.merge([
    Styles.make(
      ~height="16px",
      ~marginRight="1em",
      ~marginTop="0",
      ~width="16px",
      ()
    ) |> Styles.className,
    Styles.make(~marginTop="-6px", ()) |> Styles.small,
  ]);

let make = children => {
  ...component,
  render: _self =>
    <div className>
      <svg xmlns="http://www.w3.org/2000/svg" viewBox enableBackground=("new " ++ viewBox)>
        {ReasonReact.createDomElement("g", ~props=Js.Obj.empty(), children)}
      </svg>
    </div>
};
