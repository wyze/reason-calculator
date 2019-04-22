[@react.component]
let make = () => {
  let value = React.useReducer(Store.reducer, []);

  <Store.Provider value> <App /> </Store.Provider>;
};
