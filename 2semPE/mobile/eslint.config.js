// https://docs.expo.dev/guides/using-eslint/
const { defineConfig } = require("eslint/config");
const expoConfig = require("eslint-config-expo/flat");

module.exports = defineConfig([
  expoConfig,
  {
    ignores: ["dist/*"],
    plugins: ["@typescript-eslint", "tsdoc", "prettier"],
    extends: [
      "plugin:@typescript-eslint/recommended",
      "plugin:prettier/recommended",
    ],
    parser: "@typescript-eslint/parser",
    parserOptions: {
      project: "./tsconfig.json",
      tsconfigRootDir: __dirname,
      ecmaVersion: 2018,
      sourceType: "module",
    },
    rules: {
      "tsdoc/syntax": "warn",
      "prettier/prettier": ["warn", { singleQuote: true, semi: true }],
    },
  },
]);
