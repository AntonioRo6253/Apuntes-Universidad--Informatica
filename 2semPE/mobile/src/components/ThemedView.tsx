import { View, type ViewProps } from "react-native";

import { useThemeColor } from "@/src/hooks/useThemeColor";

export type ThemedViewProps = ViewProps & {
  lightColor?: string;
  darkColor?: string;
};

export function ThemedView({
  style,
  lightColor,
  darkColor,
  ...otherProps
}: ThemedViewProps) {
  const backgroundColor = useThemeColor(
    { light: lightColor, dark: darkColor },
    "background"
  );

  return (
    <View
      style={[
        {
          backgroundColor: Array.isArray(backgroundColor)
            ? backgroundColor[0]
            : backgroundColor,
        },
        style,
      ]}
      {...otherProps}
    />
  );
}
