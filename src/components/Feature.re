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
    Styles.merge [
      Styles.make
        alignItems::"center"
        display::"flex"
        flexBasis::"40%"
        height::"2em"
        ()
      |> Styles.className,
      Styles.make flexBasis::"35%" () |> Styles.small,
    ];

  let render { props: { emoji, text } } =>
    <div className>
      (getEntity emoji)
      <h3>(ReactRe.stringToElement text)</h3>
    </div>;
};

include ReactRe.CreateComponent Feature;

let createElement ::emoji ::text => wrapProps { emoji, text };
