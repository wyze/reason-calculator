module Title = {
  include ReactRe.Component;
  let name = "Title";

  type props = ();

  let className: string =
    Styles.make fontSize::"1.5em" () |> Styles.className;

  let render _ =>
    <h1 className>
      (ReactRe.stringToElement "Reason Calculator")
    </h1>;
};

include ReactRe.CreateComponent Title;

let createElement = wrapProps ();
