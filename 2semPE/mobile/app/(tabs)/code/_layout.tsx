import React from "react";
import { Stack } from "expo-router";

export default function CodeLayout() {
  return (
    <Stack>
      {/* index -> /code/index será la pantalla principal dentro del tab "Code" */}
      <Stack.Screen
        name="index"
        options={{ headerShown: true, title: "Code" }}
      />
      {/* otras pantallas dentro de /code no generarán tabs, sino navegacion en stack */}
      <Stack.Screen
        name="SelectivaSimple"
        options={{ title: "Selectiva Simple" }}
      />
    </Stack>
  );
}
