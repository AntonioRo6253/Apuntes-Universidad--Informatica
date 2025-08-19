import { Tabs } from "expo-router";
import React from "react";
import { Platform } from "react-native";

import { HapticTab } from "@/components/HapticTab";
import TabBarBackground from "@/components/ui/TabBarBackground";
import { Colors } from "@/constants/Colors";
import { useColorScheme } from "@/hooks/useColorScheme";
import MaterialCommunityIcons from "@expo/vector-icons/MaterialCommunityIcons";
import Entypo from "@expo/vector-icons/Entypo";

export default function TabLayout() {
  const colorScheme = useColorScheme();

  return (
    <Tabs
      screenOptions={{
        tabBarActiveTintColor: Colors[colorScheme ?? "light"].tint,
        headerShown: false,
        tabBarButton: HapticTab,
        tabBarBackground: TabBarBackground,
        tabBarStyle: Platform.select({
          ios: {
            position: "absolute",
          },
          default: {},
        }),
      }}
    >
      <Tabs.Screen
        name="index"
        options={{
          title: "Welcome",
          tabBarIcon: ({ color }) => (
            <Entypo name="hand" size={24} color={color} />
          ),
        }}
      />
      <Tabs.Screen
        name="code"
        options={{
          title: "Code",
          tabBarIcon: ({ color }) => (
            <MaterialCommunityIcons
              name="code-braces-box"
              size={24}
              color={color}
            />
          ),
        }}
      />
    </Tabs>
  );
}
