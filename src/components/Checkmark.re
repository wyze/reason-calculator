module Checkmark = {
  include ReactRe.Component;
  let name = "Checkmark";

  type props = ();

  let render _ =>
    <Svg>
      <circle cx="32" cy="32" r="30" fill="#4bd37b" />
      <path fill="#fff" d="m46 14l-21 21.6-7-7.2-7 7.2 14 14.4 28-28.8z" />
    </Svg>;
};

include ReactRe.CreateComponent Checkmark;

let createElement = wrapProps ();
