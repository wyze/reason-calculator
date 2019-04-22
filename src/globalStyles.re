open Css;

/* Resets */
global("html, body, h1, h2, h3", [margin(`zero), padding(`zero)]);
global("h1, h2, h3", [fontSize(pct(100.)), fontWeight(`normal)]);
global("button", [margin(`zero)]);

/* Box sizing */
global("html", [boxSizing(`inherit_)]);
global("*, *:after, *:before", [boxSizing(`borderBox)]);

/* Global styles */
global(
  ":root",
  [
    fontSize(em(0.75)),
    media(
      "(min-width: 25em) and (max-width: 93.75em)",
      [
        /* Using unsafe here because too much math */
        unsafe(
          "fontSize",
          "calc(.75em + (18 - 12) * ((100vw - 25em) / (1500 - 400)))",
        ),
      ],
    ),
    media("(min-width: 93.75em)", [fontSize(em(1.125))]),
  ],
);
global(
  "html",
  [
    lineHeight(`abs(1.45)),
    unsafe("MozOsxFontSmoothing", "grayscale"),
    unsafe("WebkitFontSmoothing", "antialiased"),
    overflowX(hidden),
    unsafe("textRendering", "optimizeLegibility"),
  ],
);
global(
  "body",
  [
    background(hex("efefef")),
    color(hex("838383")),
    display(`flex),
    fontFamily(
      [|
        "-apple-system",
        "BlinkMacSystemFont",
        "'Segoe UI'",
        "Roboto",
        "Helvetica",
        "Arial",
        "sans-serif",
        "'Apple Color Emoji'",
        "'Segoe UI Emoji'",
        "'Segoe UI Symbol'",
      |]
      |> Js.Array.joinWith(", "),
    ),
    height(`calc((`sub, vh(100.), em(3.)))),
    justifyContent(`center),
    marginTop(em(3.)),
  ],
);
