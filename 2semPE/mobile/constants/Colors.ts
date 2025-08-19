/**
 * Below are the colors that are used in the app. The colors are defined in the light and dark mode.
 * There are many other ways to style your app. For example, [Nativewind](https://www.nativewind.dev/), [Tamagui](https://tamagui.dev/), [unistyles](https://reactnativeunistyles.vercel.app), etc.
 */

const tintColorLight = "#3b0aa4ff";
const tintColorDark = "#2fcebeff";

export const Colors = {
  light: {
    text: "#11181C",
    background: "#fff",
    tint: tintColorLight,
    icon: "#687076",
    tabIconDefault: "#687076",
    tabIconSelected: tintColorLight,

    // constantes añadidas para componentes (WorkItem, etc.)
    accents: ["#7c2cff", "#00f0ff", "#9e2981ff", "#8ad1ff"],
    iconBackgrounds: ["#f0f6ff", "#e8fbff", "#fff0f8", "#f0fbff"], // tonos suaves para modo claro
    ripple: [
      "rgba(124,44,255,0.12)",
      "rgba(0,240,255,0.10)",
      "rgba(255,73,209,0.10)",
      "rgba(138,209,255,0.10)",
    ],
    cardBackground: "rgba(0,0,0,0.03)",
    itemTextColor: "#11181C",
    itemSubtitleColor: "#6b7280",
    borderBottomColor: "rgba(124,44,255,0.06)",
  },
  dark: {
    text: "#ECEDEE",
    background: "Transparent",
    tint: tintColorDark,
    icon: "#9BA1A6",
    tabIconDefault: "#9BA1A6",
    tabIconSelected: tintColorDark,

    // constantes añadidas para modo oscuro (coinciden con los valores usados antes)
    accents: ["#7c2cff", "#00f0ff", "#ff49d1", "#8ad1ff"],
    iconBackgrounds: ["#0f0b1a", "#12030b", "#07121a", "#0b1407"],
    ripple: [
      "rgba(124,44,255,0.12)",
      "rgba(0,240,255,0.10)",
      "rgba(255,73,209,0.10)",
      "rgba(138,209,255,0.10)",
    ],
    cardBackground: "rgba(255,255,255,0.03)",
    itemTextColor: "#e6f7ff",
    itemSubtitleColor: "#9aa6ff",
    borderBottomColor: "rgba(124,44,255,0.06)",
  },
};
