module Feature = {
  include ReactRe.Component;
  let name = "Feature";

  type emoji =
    | Checkmark
    | Soon;

  type props = {
    emoji,
    text: string,
  };

  let getEntity emoji =>
    switch emoji {
      | Checkmark => Checkmark.createElement children::[] ()
      | Soon => Soon.createElement children::[] ()
      | _ => ReactRe.nullElement
    };

  let className: string =
    Styles.make
      alignItems::"center"
      display::"flex"
      flexBasis::"35%"
      height::"2em"
      ()
    |> Styles.className;

  let render { props: { emoji, text } } =>
    <div className>
      (getEntity emoji)
      <h3>(ReactRe.stringToElement text)</h3>
    </div>;
};

include ReactRe.CreateComponent Feature;

let createElement ::emoji ::text => wrapProps { emoji, text };
