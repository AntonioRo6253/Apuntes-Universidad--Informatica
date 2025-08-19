import {
  Pressable,
  Text,
  View,
  StyleSheet,
  useColorScheme,
} from "react-native";
import { Colors } from "../constants/Colors";

type WorkItemProps = {
  numero: number | string;
  titulo: string;
  descripcion: string;
  onPress?: () => void;
};

export default function WorkItem({
  numero,
  titulo,
  descripcion,
  onPress,
}: WorkItemProps) {
  const scheme = useColorScheme() === "dark" ? "dark" : "light";
  const idx = (Number(numero) - 1) % 4;

  const accents = Colors[scheme].accents;
  const iconBgs = Colors[scheme].iconBackgrounds;
  const rippleCols = Colors[scheme].ripple;

  const accent = accents[idx];
  const iconBg = iconBgs[idx];
  const ripple = rippleCols[idx];

  return (
    <Pressable
      style={({ pressed }) => [
        styles.item,
        { backgroundColor: Colors[scheme].cardBackground },
        pressed && styles.itemPressed,
        { borderBottomColor: Colors[scheme].borderBottomColor },
      ]}
      onPress={onPress}
      android_ripple={{ color: ripple }}
    >
      <View style={styles.itemLeft}>
        <View
          style={[
            styles.iconCircle,
            {
              backgroundColor: iconBg,
              borderColor: accent,
              shadowColor: accent,
            },
          ]}
        >
          <Text
            style={[
              styles.iconText,
              { color: Colors[scheme].itemTextColor, textShadowColor: accent },
            ]}
          >
            {numero}
          </Text>
        </View>
        <View style={styles.itemTexts}>
          <Text
            style={[styles.itemText, { color: Colors[scheme].itemTextColor }]}
          >
            {titulo}
          </Text>
          <Text
            style={[
              styles.itemSubtitle,
              { color: Colors[scheme].itemSubtitleColor },
            ]}
          >
            {descripcion}
          </Text>
        </View>
      </View>
    </Pressable>
  );
}

const styles = StyleSheet.create({
  item: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
    paddingVertical: 14,
    paddingHorizontal: 16,
    backgroundColor: "rgba(255,255,255,0.03)", // tarjeta translúcida
    borderBottomWidth: 1,
    borderBottomColor: "rgba(124,44,255,0.06)",
  },
  itemPressed: {
    backgroundColor: "rgba(255,255,255,0.06)",
    transform: [{ scale: 0.995 }],
    shadowOffset: { width: 0, height: 6 },
    shadowOpacity: 0.12,
    shadowRadius: 12,
    elevation: 6,
  },
  itemLeft: {
    flexDirection: "row",
    alignItems: "center",
  },
  iconCircle: {
    width: 48,
    height: 48,
    borderRadius: 24,
    alignItems: "center",
    justifyContent: "center",
    marginRight: 12,
    borderWidth: 1.5,
    // borderColor dinámico
    shadowOpacity: 0.9,
    shadowOffset: { width: 0, height: 6 },
    shadowRadius: 14,
    elevation: 8,
  },
  iconText: {
    fontSize: 18,
    color: "#eaffff", // texto claro con contraste neon
    fontWeight: "900",
    textShadowOffset: { width: 0, height: 0 },
    textShadowRadius: 6,
  },
  itemTexts: {
    flexDirection: "column",
  },
  itemText: {
    fontSize: 16,
    color: "#e6f7ff",
    fontWeight: "700",
  },
  itemSubtitle: {
    fontSize: 12,
    color: "#9aa6ff",
    marginTop: 2,
  },
});
