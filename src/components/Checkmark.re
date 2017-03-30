module Checkmark = {
  include ReactRe.Component;
  let name = "Checkmark";

  type props = ();

  let className: string =
    Styles.make
      height::"16px"
      marginRight::"1em"
      marginTop::"-6px"
      width::"16px"
      ()
    |> Styles.className;

  let render _ =>
    <div className>
      <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 64 64" enableBackground="new 0 0 64 64">
        <circle cx="32" cy="32" r="30" fill="#4bd37b" />
        <path fill="#fff" d="m46 14l-21 21.6-7-7.2-7 7.2 14 14.4 28-28.8z" />
      </svg>
    </div>;
};

include ReactRe.CreateComponent Checkmark;

let createElement = wrapProps ();
